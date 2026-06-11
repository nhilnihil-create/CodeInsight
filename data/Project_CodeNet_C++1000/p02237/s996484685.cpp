#include<iostream>
using namespace std;
typedef struct{
  int A[1000];
}node;
node T[105];
int main(){
  int n;
  int num;
  int son;
  int z;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>num;
    cin>>son;
    for(int j=0;j<son;j++){
      cin>>z;
      T[num].A[z]=1;
      }
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      if(j==1)cout<<T[i].A[j];
      else cout<<" "<<T[i].A[j];
    }
    cout<<endl;
  }
  return 0;
}