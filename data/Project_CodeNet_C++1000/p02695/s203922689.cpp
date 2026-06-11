#include <bits/stdc++.h>
using namespace std;
#define int long long

bool isprime(int n){
    double rootn = sqrt(n);
    if (n < 2){
        return false;
    }
    else if (n == 2){
        return true;
    }
    else if (n % 2 == 0){
        return false;
    }
    else{
        for(int i = 3; i <= rootn; i += 2){
            if(n % i == 0){
                return false;
            }
        }
        return true;
    }
}

int point(vector<tuple<int, int, int, int>> dabc, vector<int> A){
    int ans = 0;
    for(int i=0; i<dabc.size(); i++){
        if(A[get<2>(dabc[i])] - A[get<1>(dabc[i])] == get<3>(dabc[i])){
            ans += get<0>(dabc[i]);
        }
    }
    return ans;
}

void max_point(vector<tuple<int, int, int, int>> dabc, int M, vector<int>& A, int j, int& now_max){
    if(j == A.size()){
        int now_point = point(dabc, A);
        if(now_point > now_max){
            now_max = now_point;
        }
    }
    else{
        // いまから j 番目の添え字をいじる
        int f = 1;
        if(j > 0){
            f = A[j-1];
        }
        for(int i=f; i<=M; i++){
            A[j] = i;
            max_point(dabc, M, A, j+1, now_max);
        }
    }
}

signed main(){
    int N, M, Q;
    cin >> N >> M >> Q;
    vector<tuple<int, int, int, int>> dabc;
    for(int i=0; i<Q; i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        dabc.push_back(make_tuple(d, a, b, c));
    }
    sort(dabc.begin(), dabc.end());

    vector<int> A(N+1, 1);
    int max = 0;
    max_point(dabc, M, A, 1, max);
    cout << max << endl;

    return 0;
}