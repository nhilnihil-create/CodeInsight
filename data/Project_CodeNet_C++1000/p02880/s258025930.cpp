#include <iostream>
#include<vector>
#include<iomanip>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<set>
#include<map>
#define INF 1e8
using namespace std;
#define ll long long

#define MAX 100020
#include <iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<set>
#include<map>
#define INF 1e8
using namespace std;
#define ll long long

#define MAX 100020

int main(){
int a,b,n;
  cin>>n;
  for(int i=1;i<=9;i++){
      for(int j=1;j<=9;j++){
          if(n==i*j){
              cout<<"Yes";
              return 0;
          }
      }
  }
  cout<<"No";
}

