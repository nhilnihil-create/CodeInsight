#include<iostream>
using namespace std;
int main()
{
    long long n,i,count,m;

    cin >> n;

    long long p[n];

    for(i=0; i<n; i++)
        cin >> p[i];

    m = p[0];
    count = 1;

    for(i=1; i<n; i++)
    {
        if(p[i]<=m){
            count++;
            m = p[i];
        }
    }

    cout << count << '\n';
}
