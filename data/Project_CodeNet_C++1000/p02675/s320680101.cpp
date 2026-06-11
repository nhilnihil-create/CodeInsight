#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
typedef long long ll;
typedef pair<int,int> P;

int main(){
  int n;
  cin>>n;

  switch(n%10){
      case 2: cout<<"hon"<<endl;
        break;
      case 4: cout<<"hon"<<endl;
        break;
      case 5: cout<<"hon"<<endl;
        break;
      case 7: cout<<"hon"<<endl;
        break;
      case 9: cout<<"hon"<<endl;
        break;
      case 0: cout<<"pon"<<endl;
        break;
      case 1: cout<<"pon"<<endl;
        break;
      case 6: cout<<"pon"<<endl;
        break;
      case 8: cout<<"pon"<<endl;
        break;
      case 3: cout<<"bon"<<endl;
        break;
  }
}