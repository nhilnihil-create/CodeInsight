/*
    -ensure correct output format
    -ensure printing required output
    -reread the problem statement
  */

#include<bits/stdc++.h>
using namespace std;
typedef long long ull;
typedef unsigned long long ll;
typedef pair<ll,ll>pll;
typedef pair<ll,pair<ll,ll>>plll;
#define fastread() (ios_base:: sync_with_stdio(false),cin.tie(NULL));
#define vll(v) v.begin(),v.end()
#define all(x) x.rbegin(),x.rend()
#define min3(a, b, c)   min(a, min(b, c))
#define max3(a, b, c)   max(a, max(b, c))
#define F first
#define S second
#define in  freopen("input.txt", "r", stdin)
#define out  freopen("output.txt", "w", stdout)
#define minheap int,vector<int>,greater<int>
#define pb push_back
#define eb emplace_back
#define ischar(x)  (('a' <= x && x <= 'z') || ('A' <= x && x <= 'Z'))
#define isvowel(ch) ((ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')||(ch=='A'|| ch=='E' || ch=='I'|| ch=='O'|| ch=='U'))
#define bug cout<<"BUG"<<endl;
const ull Max = 1e18 ;
const int Mod = 1e9 + 7;
const double PI  =3.141592653589793238463;
bool compare(const pair<ll,ll> &a, const pair<ll,ll> &b)
{
    return (a.first > b.first);
}
ll lcm(ll a,ll b)
{
    if(a==0 || b==0)return 0;

    return a/__gcd(a,b)*b;
}

void input(ll ara[],ll n)
{
    for(ll i=0; i<n; i++)cin>>ara[i];
}


string multiply(string num1, string num2)
{
    int len1 = num1.size();
    int len2 = num2.size();
    if (len1 == 0 || len2 == 0)
        return "0";

    // will keep the result number in vector
    // in reverse order
    vector<int> result(len1 + len2, 0);

    // Below two indexes are used to find positions
    // in result.
    int i_n1 = 0;
    int i_n2 = 0;

    // Go from right to left in num1
    for (int i=len1-1; i>=0; i--)
    {
        int carry = 0;
        int n1 = num1[i] - '0';

        // To shift position to left after every
        // multiplication of a digit in num2
        i_n2 = 0;

        // Go from right to left in num2
        for (int j=len2-1; j>=0; j--)
        {
            // Take current digit of second number
            int n2 = num2[j] - '0';

            // Multiply with current digit of first number
            // and add result to previously stored result
            // at current position.
            int sum = n1*n2 + result[i_n1 + i_n2] + carry;

            // Carry for next iteration
            carry = sum/10;

            // Store result
            result[i_n1 + i_n2] = sum % 10;

            i_n2++;
        }

        // store carry in next cell
        if (carry > 0)
            result[i_n1 + i_n2] += carry;

        // To shift position to left after every
        // multiplication of a digit in num1.
        i_n1++;
    }

    // ignore '0's from the right
    int i = result.size() - 1;
    while (i>=0 && result[i] == 0)
        i--;

    // If all were '0's - means either both or
    // one of num1 or num2 were '0'
    if (i == -1)
        return "0";

    // generate the result string
    string s = "";

    while (i >= 0)
        s += std::to_string(result[i--]);

    return s;
}

bool comp(string str)
{
    string ptr="1000000000000000000";

    if(str.size()>ptr.size())
        return false;

    if(str.size()==ptr.size())
    {
        for(ll i=0; i<str.size(); i++)
        {
            if(str[i]>ptr[i])
                return false;
        }
    }
    return true;
}


int main()
{

    fastread();

    ll j,n,m,p,a,sum=0,k,t,b,c,d,cnt=0,q,l,r;

    bool flag=false;

    string str;


    int i;

    cin>>n;

    ll ara[n+3];

    for(i=0; i<n; i++)
    {
        cin>>ara[i];

        if(ara[i]==0)cnt=1;
    }



    sum=ara[0];

    if(cnt)cout<<0<<endl;

    else
    {
        cnt=0;

        string str1=to_string(sum);

        sort(ara,ara+n);

        for(i=1; i<n; i++)
        {

            string str2 = to_string(ara[i]);

            if((str1.at(0) == '-' || str2.at(0) == '-') &&
                    (str1.at(0) != '-' || str2.at(0) != '-' ))
                cout<<"-";


            if(str1.at(0) == '-' && str2.at(0)!='-')
            {
                str1 = str1.substr(1);
            }
            else if(str1.at(0) != '-' && str2.at(0) == '-')
            {
                str2 = str2.substr(1);
            }
            else if(str1.at(0) == '-' && str2.at(0) == '-')
            {
                str1 = str1.substr(1);
                str2 = str2.substr(1);
            }

            str1=multiply(str1,str2);

            if(!comp(str1))
            {
                cnt=1;
                break;

            }

        }

        if(cnt)cout<<-1<<endl;

        else cout<<str1<<endl;
    }


}

