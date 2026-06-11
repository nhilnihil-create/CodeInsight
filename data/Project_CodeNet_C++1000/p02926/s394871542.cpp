#include "bits/stdc++.h"
#define ll long long
#define ALL(x) x.begin(),x.end()
#define MOD 1000000007
using namespace std;

int main(){
ll N;
cin>>N;
vector<pair<double,double>> en(N);
vector<double> arg(N);
double tmp,tmp1;
for(int i=0;i<N;i++){
  cin>>tmp>>tmp1;
  en[i]=make_pair(tmp,tmp1);
}

double max =0;
for(int i=0;i<360;i++){
  double tarx = cosf(i);
  double tary = sinf(i);
  double tx=0;
  double ty=0;
  for(int j=0;j<N;j++){
      if((tarx*en[j].first+tary*en[j].second)>0){
        tx+=en[j].first;
        ty+=en[j].second;
      }
  }
double tans = sqrt(tx*tx+ty*ty);
if(max<tans){
  max = tans;
}

}


printf("%.20f",max);


}
