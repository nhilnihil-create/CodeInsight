#include<iostream>

using namespace std;

int n,k;
int check(long long p,int A[]){
    int i=0;
    for(int j=0;j<k;j++){
       long long s=0;
       while(s+A[i]<=p ){
       		s+=A[i++];
       		if(i==n)return n;
       }
       
    }
    return i;
}
int main(){
	
	cin>>n>>k;
	int *A=new int[n];
	int sum=0;
    for(int i=0;i<n;++i){
    	cin>>A[i];
    	sum+=A[i];
    }
    int left=sum/k-1,right=sum;
    int mid;
    while(right>left+1){
       mid=(left+right)/2;
       int v=check(mid,A);
       if(v>=n)right=mid;
       else left=mid;
    }
    cout<<right<<endl;
    
	delete A;
	return 0;

}
