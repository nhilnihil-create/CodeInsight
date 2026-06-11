#include<iostream>
using namespace std;

int main(){
  int n,m;
  int h[1500],w[1500];
  int y[1500000],x[1500000];
  int tmp;

  while(1){
    cin >> n >> m;
    if(!n && !m)break;


    int max;
    if(n>m)max = n;
    else max = m;

    for(int i=0;i<n;i++)cin >> h[i];
    for(int i=0;i<m;i++)cin >> w[i];

    for(int i=0;i<max*1000;i++){
      y[i] = 0;
      x[i] = 0;
    }

    for(int i=0;i<n;i++){
      tmp = 0;
      for(int j=i;j<n;j++){
	tmp += h[j];
	y[tmp]++;
      }
    }
    
    for(int i=0;i<m;i++){
      tmp = 0;
      for(int j=i;j<m;j++){
	tmp += w[j];
	x[tmp]++;
      }
    }

    int ans = 0;
    for(int i=0;i<max*1000;i++)ans += y[i] * x[i];

    cout << ans << endl;
  }
}