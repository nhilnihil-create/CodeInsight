#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

int main(){

  long long m=1000000007;
  long long int r=0,b=0,g=0;//それぞれ赤、青、緑の帽子の数

  int n;
  cin >> n;

  long long int l=1;

  //0人目は必ず0と言う
  long long a;
  cin >>a;
  if(a!=0){
    cout << 0 << endl;
    return 0;
  }
  r++;
  l*=3;
  for(int i=1;i<n;i++){
    cin >> a;
    //i人目の色としてあり得る色の数をlにかけていく
    if(r==a){
      if(b==a){
        if(g==a){
          l*=3;
          l%=m;
          r++;
        }
        else{
          l*=2;
          l%=m;
          r++;
        }
      }
      else{
        if(g==a){
          l*=2;
          l%=m;
          r++;
        }
        else{
          r++;
        }
      }
    }
    else{
      if(b==a){
        if(g==a){
          l*=2;
          l%=m;
          b++;
        }
        else{
          b++;
        }
      }
      else{
        if(g==a){
          g++;
        }
        else l=0;
      }
    }
  }

  cout << l%m << endl;
}