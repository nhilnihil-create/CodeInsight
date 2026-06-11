#include <iostream>
using namespace std;
int main()
{
  int N;
  cin>>N;
  int arr[N];
  int count=0;
  for(int i=1;i<=N;i++){
    cin>>arr[i];
  }
  for(int i=1;i<=N;i++){
    if(i%2!=0 && arr[i]%2!=0){
      count++;
    }
  }
     cout<<count;
  return 0;
}