#include <bits/stdc++.h>
using namespace std;

int main() {
    
    long long int n,left=0,right,count=0;
    cin>>n;
    string s;
    char temp;
    cin>>s;
    right=n-1;
    while(left<=right)
    {
        while(left<n && s[left]=='R') 
		left++;
        while(right>=0 && s[right]=='W') 
		right--;
        if(left<right){
        	temp=s[left];
        	s[left]=s[right];
        	s[right]=temp;
			count++;
//			cout<<s<<endl;
		}
    }
    cout<<count;
	return 0;
}
