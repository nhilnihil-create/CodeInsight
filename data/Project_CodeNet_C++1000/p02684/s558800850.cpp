#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    unsigned long long int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for(int i = 0; i < N; i++)  {
        cin >> A[i];
    }
    
    vector<int> order(N, -1);
    int crossNum, modNum;
    for(int i = 0, num = 0; true ; i = A[i] - 1, num++){
        if(order[i] == -1){
            order[i] = num;
        }
        else{
            modNum = num - order[i];
            crossNum = order[i];
            break;
        }
    }
    int ans = 0;
    int maxv = K <= crossNum ? K : (crossNum + (K - crossNum) % modNum);
    for(int i = 0; i < maxv; i++){
        ans = A[ans] - 1;
    }
    cout << ans + 1 << endl;
	return 0;
}