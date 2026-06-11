#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

main()
{
    int n, c = 0;
    cin >> n;
    int arr[n];
    vector<int> v = {0};
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if(i >= 1){
            if(arr[i-1] >= arr[i]){
                c++;
                v.push_back(c);
            }
            else{
                c = 0;
            }
        }
    }
    cout << *max_element(v.begin(), v.end()) << endl;


}





///promy_pompom
//hello world
