#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int N;
    cin >> N;

    long long sum = 0;
    for(int i = 0;i <= N;i++){
        if(i %3 == 0) {

        }
        else if(i % 5 == 0) {

        }
        else{
            sum += i;
        }
    }
    cout << sum << endl;
    return 0;
}