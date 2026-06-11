#include<bits/stdc++.h>

using namespace std;

int main(){
    int p,n;
    cin>>p>>n;
    map<int,int>penalty;
    set<int>ac;
    for(int i=0;i<n;i++)
    {
        int k;
        string s;
        cin>>k>>s;
        if(s=="AC")
        {
         ac.insert(k);
        }
        else
        {
            if(ac.count(k)==0)
                ++penalty[k];
        }
    }
    long int ans=0;
    for(map<int,int>::iterator it=penalty.begin();it!=penalty.end();it++)
    {
        if(ac.count(it->first)==1)
        ans+=(it->second);
    }
    cout<<ac.size()<<" "<<ans;
	return 0;
}
