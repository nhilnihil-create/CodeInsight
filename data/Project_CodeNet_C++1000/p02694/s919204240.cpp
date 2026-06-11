#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int x, sum = 100, year = 0; cin>>x;
    while(sum < x)
    {
        sum = sum + (sum / 100);
        year++;
    }
    cout<<year<<endl;
}
