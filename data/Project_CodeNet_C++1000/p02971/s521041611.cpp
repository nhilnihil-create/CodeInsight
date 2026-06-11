#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
typedef long long ll;
#define SORT(s) sort((s).begin(),(s).end())
#define SORTD(s) sort((s).rbegin(),(s).rend())

int main() {
  int n;
  cin>>n;
  
  vector<int> a(n);
  vector<int> s(n);
  rep(i,n){cin>>a[i];
  s[i]=a[i];
          }
  SORTD(s);
  
  int max=s[0];
  
  for(int i=0;i<n;i++){
    if(max==a[i]&&s[0]!=s[1]){
    	cout<<s[1]<<endl;
    }
    
    else{
    	cout<<s[0]<<endl;
    }

  }
}