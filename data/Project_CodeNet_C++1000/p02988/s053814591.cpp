#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

main()
{
    int n, c = 0;;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    for(int i = 0; i < n - 2; i++){
        int arr1[] = {arr[i], arr[i+1], arr[i+2]};
        if(arr[i+1] != *max_element(arr1, arr1+3) && arr[i+1] != *min_element(arr1, arr1+3)){
            c++;
        }

    }
    cout << c;


}





///promy_pompom
//hello world
