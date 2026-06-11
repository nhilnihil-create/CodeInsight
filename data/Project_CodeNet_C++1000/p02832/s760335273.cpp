#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;  cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];

    int value = 1;
    int cnt = 0;

    for(int i=0; i<n; i++){
        if(a[i] == value) { cnt++; value++;}
    }

    if(!cnt) cout << "-1" << endl;
    else cout << n-cnt<< endl;
    return 0;
    
}