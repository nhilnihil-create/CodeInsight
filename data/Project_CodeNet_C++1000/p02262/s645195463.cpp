#include<iostream>
#include<vector>
using namespace std;

const int MAX=1000001;
int N;
int A[MAX];
int count=0;
vector<int>F;
void insertionsort(int A[],int g){
	
	for(int i=g;i<N;i++){
		int j=i-g;
	   while(j>=0 && A[j]>A[j+g]){
         swap(A[j],A[j+g]);
		 j=j-g;
		count++;
	   }
	}
}

void shellsort(int A[]){
  for(int h=1;;)
  {
	  if(h>N)break;
	  F.push_back(h);
	  h=3*h+1;
  }
  for(int i=F.size()-1;i>=0;i--){
	insertionsort(A,F[i]);
  }
}



int main()
{
	cin>>N;
	for(int i=0;i<N;i++)
		cin>>A[i];
	shellsort(A);

	cout<<F.size()<<endl;
	cout<<F[F.size()-1];
	for(int i=F.size()-2;i>=0;i--)
		cout<<" "<<F[i];
	cout<<endl;
	cout<<count<<endl;
	for(int i=0;i<N;i++)
		cout<<A[i]<<endl;
	return 0;

}