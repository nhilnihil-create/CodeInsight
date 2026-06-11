#include <iostream>
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int n;
    cin>>n;
    vector<int>d(n);
    for(int i=0;i<n;i++)cin>>d[i];

    int sum=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            sum+=d[i]*d[j];
        }
    }

cout<<sum;

    return 0;
}
