#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    string s;
    cin>>s;
    int n = s.length();
    int * ans = new int[n]();
    int* rmoves = new int[n]();
    int* lmoves = new int[n]();

    int curr =0;
    for(int i=n-1;i>=0;i--)
    {
        if( s[i] == 'R')
        {
            curr++;
            rmoves[i] = curr;
        }
        else curr = 0;
    }
    curr =0;
    for(int i=0;i<n;i++)
    {
        if( s[i] == 'L')
        {
            curr++;
            lmoves[i] = curr;
        }
        else curr = 0;
    }


    for( int i=0;i<n;i++)
    {
        int moves =0;
        if( s[i] == 'L')
        {
            int moves = lmoves[i];
            int index = i-moves;
            if( moves%2 == 0)
            {
                ans[index]++;
            }
            else ans[index+1] ++;
        }
        if( s[i] == 'R')
        {

            moves = rmoves[i];
           int index = i + moves;
            if( moves%2 == 0)
            {
                ans[index]++;
            }
            else ans[index-1] ++;
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<ans[i] <<" ";

    }

}