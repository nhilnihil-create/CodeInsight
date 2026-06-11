#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
        int n;
        cin>>n;
        string s;
        cin>>s;
        for(int i=0;i<s.size();i++)
        {
            int k=s[i]-'A'+n;
            //cout<<k<<endl;
            if(k>25)
            {
                int r=k%26;
                //cout<<"R"<<r<<endl;
                cout<<char('A'+r);
            }
            else
            cout<<char('A'+k);
        }
}
