#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    std::vector<int>v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    for(int i=0;i<n;i++)
    {
        if(v[i]%2==0)
        {
            if(v[i]%3!=0&&v[i]%5!=0)
            {
                cout<<"DENIED\n";
                return 0;
            }
            
        }
    }
    cout<<"APPROVED\n";
        // your code goes here
	return 0;
}
