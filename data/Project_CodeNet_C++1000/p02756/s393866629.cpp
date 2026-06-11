#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    string s;
    cin>>s;
    queue<char> beginning , ending;
    ll q;
    cin>>q;
    ll checker = 1;
    while( q--)
    {
        int t;
        cin>>t;
        if( t== 1)
        {
            if( checker == 1)
                checker = 2;
            else checker = 1;
        } else
        {
            int f ;
            char c;
            cin>>f>>c;
            if( f== 1 && checker == 1)
            {
                beginning.push(c);
            }
            else if( f== 1 && checker == 2)
            {
                ending.push( c);
            }
            if( f== 2 && checker == 1 )
                ending.push(c);
            if( f== 2 && checker == 2)
                beginning.push(c);
        }
    }
    string bstring , estring;
    while( !beginning.empty() ) {
        bstring.push_back( beginning.front() );
        beginning.pop();
    }
    while( !ending.empty() )
    {
        estring.push_back( ending.front() );
        ending.pop();
    }
    if( checker == 2)
    {
        reverse( estring.begin() , estring.end() );
        reverse( s.begin() , s.end() );
        s = estring + s;
        s = s+ bstring;
    }
    else
    {
        reverse( bstring.begin() ,bstring.end() );
        s= bstring + s;
        s += estring;
    }
    cout<<s;
}