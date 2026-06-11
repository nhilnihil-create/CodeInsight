#include<bits/stdc++.h>
using namespace std;
int main() 
{ 
	int n;
	cin>>n;
	vector<long long>a;
    long long sum=0;  
    for(int i=0;i<n-1;i++) {
        long long x;
        cin>>x;
        a.push_back(x);
    }
    sum=a[0];
    for(int i=1;i<n-1;i++){
        sum+=(min(a[i],a[i-1]));
    }
    cout<<sum+a[n-2];
    return 0; 
} 
