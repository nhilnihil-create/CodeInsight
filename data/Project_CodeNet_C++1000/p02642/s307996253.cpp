#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int N; cin >> N;
    vector<int> A(N);
    for(int i=0; i < N; i++){
        cin >> A[i];
    }
    sort(A.begin(),A.end());
    vector<int> hantei(1000000,0);

    int temp=-1;
    for(int i: A){
        if(temp == i){
        hantei[i] += 1;
        continue;
        }
        temp = i;
        for(int j=i+i; j <= 1000000; j+=i){
            hantei[j] += 1;
        }
    }

    int count =0;
    for(int i: A){
        if(hantei[i] == 0) count++;
    }

    cout << count << endl;
    return 0;
}