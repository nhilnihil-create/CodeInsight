#include<iostream>
using namespace std;
#define int long long int
#define mod 1000000007
#define fast_input() ios:base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
int32_t main()
{
    
    string str;
    cin>>str;
    int answer=0;
    string prev="";
    prev+=str[0];
    answer++;
    int j;
    int n=str.size();
    for(j=1;j<n;j++)
    {
		if(j+1<n)
		{
			string curr="";
			curr+=str[j];
			if(curr!=prev)
			{
				answer++;
				prev=curr;
			}
			else
			{
				answer++;
				curr+=str[j+1];
				prev=curr;
				j++;
			}
		}
		else
		{
			string curr="";
			curr+=str[j];
			if(curr==prev)
			{
				break;
			}
			else
			{
				answer++;
				break;
			}
		}
	}
	cout<<answer<<endl;
}
