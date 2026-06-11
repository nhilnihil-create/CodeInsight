#include<iostream>
#include<cstdio>
#include<climits>
using namespace std;
  int n;

int m[101][101];
  int p[101];
void chain(){
  int n1;
  int j;
  int q;
  n1=n;
  //ok
  // cout <<"n1 "<<n1<<endl;
  for(int i=1;i<=n1;i++){
    m[i][i]=0;
  }
  for(int l=2;l<=n1;l++){
    for(int i=1;i<=n1-l+1;i++){
      j=i+l-1;
      m[i][j] = INT_MAX;
      for(int k=i;k<=j-1;k++){
	q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
	//	cout<<"q "<<q<<endl;
	if(q<m[i][j]){
	  m[i][j]=q;
	  //	  cout<<s[i][j]<<endl;
	}
      }
    }
  }
}

int main(){

  int A[101][2];
  cin>>n;
  int i;
  for(i=0;i<n;i++){
    cin>>A[i][0]>>A[i][1];
    p[i]=A[i][0];
  }
  p[i]=A[i-1][1];

  //ok
  /*
 for(int i=0;i<=n;i++){
   cout<<"p "<<p[i]<<endl;
 }
  */
  chain();
  /*  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cout<<m[i][j]<<endl;
    }
   }
*/
  cout<<m[1][n]<<endl;

  return 0;
}