#include <bits/stdc++.h>
#include <limits>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
#define fi(i, n) for( int i=0 ; i<n ; i++ )
#define f(i, a, b) for( int i=a ; i<b ; i++ )
#define vi vector<int>
#define pb push_back
#define MOD 1000000007
int main()
{
    int n;
    cin>>n;
    int arr[n];
    //map<int,int>mp;
    map<int , pair<int ,int > > mp;
    // will store the values and their first and last indices
    fi(i,n)
    {
        cin>>arr[i];
        if(mp.find(arr[i]) == mp.end())
        {
            mp[arr[i]].first = i + 1;
            mp[arr[i]].second = i + 1;
        }
        else
        {
            mp[arr[i]].second = i + 1;
        }
    }
	/*
    for(auto it = mp.begin();it!=mp.end();it++)
    {
        cout<<it->first<<" "<<it->second.first<<" "<<it->second.second<<endl;
    }
    */
    int count =0;
    int prev_index = 0;
    int dis = 1;
    for(auto it = mp.begin();it!=mp.end();it++)
    {
    	int fir = it->second.first;
    	int las = it->second.second;
    	if(it->first != dis)
    	{
    		break;
    	}
    	else if(las<prev_index)
    	{
    		break;
    	}
    	else 
    	{
    		if(fir>prev_index)
    		{
    			prev_index = fir;
    			count++;
    		}
    		else if(las>prev_index)
    		{
    			prev_index = las;
    			count++;
    		}
    	}
    	dis++;
    }
    if(count==0)
    	cout<<"-1";
    else 
    	cout<<n - count;



}
