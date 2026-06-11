#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int n; cin >> n;
    string ans = "No";

    for(int i = 1; i <= 9; i++){
        for (int j = i; j <= 9; j++){
            if(n == i*j){
                ans = "Yes";
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
