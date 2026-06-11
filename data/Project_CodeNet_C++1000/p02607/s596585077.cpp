#include<iostream>
using namespace std;
int main()
{
    int N, count = 0;
    cin >> N;
    int  a[N];
    for(int i = 0; i < N; i++){
        cin >> a[i];
        if(a[i] % 2 != 0 && (i+1) % 2 != 0){
            count++;
        }
        else{
            continue;
        }
    }
    cout << count;
}
