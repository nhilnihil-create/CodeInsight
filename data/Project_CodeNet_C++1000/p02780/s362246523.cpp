#include<bits/stdc++.h>

using namespace std;



int main(){


 
 ios_base::sync_with_stdio(NULL); 
 cin.tie(0);
  #ifndef ONLINE_JUDGE
  freopen ("input.txt", "r", stdin);
  freopen ("outt.txt", "w", stdout);
#endif

  int n;
  cin>>n;
  int k;
  cin>>k;
  vector< double  > arr(n);
  for(int i=0;i<n;i++){
    int a;
    cin>>a;
    arr[i]=(double(a) +1.0)/2;
  }

  double maxx = 0.0;
  for(int i=0;i<min(k,n);i++){
    maxx+= arr[i];
  }
  double  temp = maxx;
  for(int i=k;i<n;i++){
    temp +=(-1*arr[i-k]+arr[i]) ;
    maxx = max(maxx,temp);


  }
  printf("%.8f\n",maxx );

}