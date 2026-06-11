#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> P;

int main()
{
    int N;
    cin >> N;
    vector<int> A(N);
    int count = 0;
    for(int i=0;i<N;++i){
        cin >> A[i];
        if(A[i] > 0){
            ++count;
        }
    }

    int x;
    vector< P > ans;
    if(count >= N-1){
        sort(A.begin(), A.end());
        x = A[0];
        for(int i=1;i<N-1;++i){
            ans.push_back(P(x, A[i]));
            x -= A[i];
        }
        ans.push_back(P(A[N-1], x));
    }
    else if(count <= 1){
        sort(A.begin(), A.end(), greater<int>());
        x = A[0];
        for(int i=1;i<N;++i){
            ans.push_back(P(x, A[i]));
            x -= A[i];
        }
    }
    else{
        sort(A.begin(), A.end());
        x = A[0];
        int y = A[N-1];
        for(int i=1;i<N-1;++i){
            if(A[i] < 0){
                ans.push_back(P(y, A[i]));
                y -= A[i];
            }
            else{
                ans.push_back(P(x, A[i]));
                x -= A[i];
            }
        }
        ans.push_back(P(y, x));
    }

    cout << ans.back().first - ans.back().second << endl;
    for(P p : ans){
        cout << p.first << " " << p.second << endl;
    }
}
