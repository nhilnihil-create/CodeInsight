#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;

int main(){
  int n,m,ma[100010],h[100001];
  cin >> n >> m;
  for(int i=1;i<=n;i++){
    cin >> h[i];
    ma[i] = 0;
  }
  for(int i=1;i<=m;i++){
    int a,b;
    cin >> a >> b;
    
    ma[a] = max(ma[a],h[b]);
    ma[b] = max(ma[b],h[a]);
  }
  
  int count = 0;
  
  for(int i=1;i<=n;i++){
    if(ma[i]<h[i]){
      count++;
    }
  }
  
  cout << count << endl; 
    
}
  

