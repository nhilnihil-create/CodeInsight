#include <bits/stdc++.h>
#define Tayeb ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
typedef long long ll;
using namespace std;
int main()
{
    Tayeb;
    int N,val1,count=0;
    cin >> N;
    int arr[N],arr2[N];
    for(int i=0; i<N; i++)
    {
        cin >> arr[i];
        arr2[i]=arr[i];

    }
    sort(arr,arr+N);

    for(int i=0; i<N; i++)
    {
        if(arr[i]!=arr2[i])
        count++;
    }
    if(count==0||count==2)
    cout << "YES\n";
    else
    cout << "NO\n";

    return 0;

}
