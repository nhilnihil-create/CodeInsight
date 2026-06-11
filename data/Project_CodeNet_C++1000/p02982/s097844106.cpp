#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
int main()
{
    int n,d;
    cin>>n>>d;
    int arr[n][d];
    for(int i=0;i<n;i++)
        for(int j=0;j<d;j++)
            cin>>arr[i][j];
    int sqr{},counter{};
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            sqr = 0;

            for(int k = 0;k<d;k++)
                sqr += (arr[i][k] - arr[j][k])*(arr[i][k] - arr[j][k]);
            if(floor(sqrt(sqr)) == ceil(sqrt(sqr)))
                counter++;
        }

    }
    cout<<counter;
	return 0;
}