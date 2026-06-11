#include <bits/stdc++.h>
using namespace std;
#define ll long long int 
int main()
{
    ll n,k;
    cin >> n >> k;
    ll R,P,S;
    cin >> R >> S >> P;
    vector<string> mod(k);
    string s;
    cin >> s;
    ll ans=0;
    for(ll i=0;s[i]!='\0';i++)
    {
        if(s[i]=='r')
        {
            s[i]='p';
            ans+=P;
            //cout << ans;
        }
        else if(s[i]=='s')
        {
            s[i]='r';
            ans+=R;
            //cout << ans;

        }
        else if(s[i]=='p')
        {
            s[i]='s';
            ans+=S;
            //cout << ans;
        }

    }
    //cout << ans;
    //cout << s<<"\n";
    for(ll i=0;s[i]!='\0';i++)
    {
        mod[i%k]+=s[i];
    }
    /*for(ll i=0;i<k;i++)
    {
        cout << mod[i];
        cout <<"\n";
    }*/
    ll sub=0;
    for(ll i=0;i<k;i++)
    {
        //cout << i<<"\n";
        ll count=1;
        char d=mod[i][0];
        //cout << d;
        for(ll j=1;j<mod[i].size();j++)
        {
            if(mod[i][j]==mod[i][j-1])
            {
                d=mod[i][j-1];
                count++;
                //cout <<"count value"<< count<<"\n";
            }
            else
            {
                if(d=='r')
                {
                 //   cout <<"Rock found\n";
                    sub+=(count/2)*R;
                }
                else if(d=='s')
                {
               //     cout <<"Scissor found\n";
                    sub+=(count/2)*S;
                }
                else if(d=='p')
                {
             //       cout <<"Paper found\n";
                    sub+=(count/2)*P;
                }
                count=1;

            }

        }
        if(d=='r')
        {
           // cout <<"Rock found\n";
            sub+=(count/2)*R;
        }
        else if(d=='s')
        {
         //   cout <<"Scissor found\n";
            sub+=(count/2)*S;
        }
        else if(d=='p')
        {
       //     cout <<"Paper found\n";
            sub+=(count/2)*P;
        }
        count=1;



    }
    ans-=sub;
    cout << ans;

}
