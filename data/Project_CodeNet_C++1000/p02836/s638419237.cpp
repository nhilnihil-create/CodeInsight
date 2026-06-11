#include<iostream>
#include<vector>
#define lli long long int
#define N 4
#define pb push_back
#define p 1000000007
using namespace std;


int main()
{
    string str;
    int ct = 0;
    cin>>str;
    int n = (int)str.length();
    for(int i=0;i<n/2;i++)
    {
        if(str[i]== str[n-i-1])
            continue;
        ct = ct +  1;
    }
    cout<<ct<<endl;
}
