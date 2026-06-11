#include <bits/stdc++.h>
using namespace std;
#define rep(i, seisu) for(int i = 0; i < (int)(seisu); i++)

typedef long long ll;

int main(){
 int n;
 cin >> n;
 int a, b;
 a = n/1.08;
 b = n/1.08+1;

 int aa = a * 1.08, bb = b * 1.08;

 if(aa == n){
   cout << a;
 }
else if(bb == n){
  cout << b;
}
else{
  cout << ":(";
}

}
