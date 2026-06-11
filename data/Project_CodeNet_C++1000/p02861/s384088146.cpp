#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

//int arr1[13];

//int arr2[13];

double dist(int x1, int y1, int x2, int y2)
{
    double d = sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
    return d;

}



int main()
{
    ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);

    int n;

    cin >> n;

    int arr[n];

    for(int i=0; i<n; i++)
    {
        arr[i] = i;
    }

    int arr1[n+9];
    int arr2[n+9];

    for(int i=0; i<n; i++)
    {
        cin >> arr1[i] >> arr2[i];
    }



    double sum = 0;

    do
    {
        for(int i=0; i<n-1; i++)
        {
            sum +=  dist(arr1[arr[i]], arr2[arr[i]], arr1[arr[i+1]], arr2[arr[i+1]]);
        }

    }while(next_permutation(arr, arr+n));

    ll fact = 1;

    for(int i=1; i<=n; i++)
    {
        fact *= i;
    }

    //cout << sum << " " << fact << endl;

    double res = sum / fact;

    printf("%.10lf\n", res);


}
