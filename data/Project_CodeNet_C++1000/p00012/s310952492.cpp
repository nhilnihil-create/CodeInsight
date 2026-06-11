//ツ三ツ角ツ形ABCツづ個陳?づ可点Pツつェツ甘慊づ慊づェツづゥツつゥツづ?つ、ツつゥツづ個板サツ津ィツづ個仕ツ陛サ
//ツ「ツ三ツ角ツ形ABP, BCP, CAPツづ個姪環静渉づ個債?計 == ツ三ツ角ツ形ABCツづ個姪環静渉」
//ツづ可づ按づ?づ?つ「ツづェツづ? ツ点Pツづ債三ツ角ツ形ツづ可甘慊づ慊づェツづゥ

#include <iostream>
#include <complex>
#include <cstdlib>
#include <cmath>
using namespace std;

typedef complex<double> P;

#define EPS (1e-8)

P t[3], p;

//3ツづつづ個点ツづ個湘ョツ陛アツつゥツづァ, ツ三ツ角ツ形ツづ個姪環静渉づーツ仰?づ淞づゥ
//ツヘツδ債δ督づ個古カツ篠ョツづーツ用ツつ「ツづゥ
double getArea(const P &a, const P &b, const P &c){
  double A = abs(a - b);
  double B = abs(b - c);
  double C = abs(c - a);
  double S = (A + B + C) / 2.0;

  return sqrt(S * (S - A) * (S - B) * (S - C));
}

void solve(){
  double sum = 0;

  //ABP, BCP, CAPツづ個三ツ角ツ形ツづ個姪環静渉づーツ仰?づ淞づ? ツ堕ォツつオツ債?づュツつケツづゥ
  for(int i = 0; i < 3; i++){
    sum += getArea(t[i], t[(i + 1) % 3], p);
  }

  //ツ三ツ角ツ形ABCツづ個姪環静渉づーツ仰?づ淞づゥ
  double abc = getArea(t[0], t[1], t[2]);

  //sumツづ?bcツづ個債キツつェ, ツ古?づィツづ按つュ0ツづ可凝淞つ「ツづ按づァツ督卍つオツつ「ツづ個づ? YES
  if(fabs(sum - abc) < EPS){
    cout << "YES\n";
  }
  else{
    cout << "NO\n";
  }
}

int main(){
  while(true){
    for(int i = 0; i < 3; i++){
      if(!(cin >> t[i].real() >> t[i].imag())) return 0;
    }
    cin >> p.real() >> p.imag();
    solve();
  }
}