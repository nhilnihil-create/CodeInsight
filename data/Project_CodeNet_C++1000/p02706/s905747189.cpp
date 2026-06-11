#include<iostream>
using namespace std;
int main()
{
	int N,M;
	int A[10000];
	int B=0;
	cin>>N>>M;
	for(int i=0;i<M;i++){
		cin>>A[i];
  		B=B+A[i];
    }
  	if(N>=B)
      cout<<N-B<<endl;
  	else
      cout<<-1<<endl;
}