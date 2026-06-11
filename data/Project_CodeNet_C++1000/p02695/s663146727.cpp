#include <bits/stdc++.h>

using namespace std;

void print(const std::vector<int>& v)
{
  std::for_each(v.begin(), v.end(), [](int x) {
    std::cout << x << " ";
  });
  std::cout << std::endl;
}

int main(void)
{
    int N, M, Q;
    cin >> N >> M >> Q;
    vector<int> a(Q);
    vector<int> b(Q);
    vector<int> c(Q);
    vector<int> d(Q);

    for(int i = 0; i < Q; i++) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }

    vector<int> v;
    if(M == 1){
        int sum = 0;
        for(int i = 0; i < Q; i++) {
            if(0 == c[i]) {
                sum += d[i];
            }
        }
        cout << sum << endl;
        return 0;
    }
    else {
        for(int i = 0;i < M - 1;i++) {
            v.push_back(0);
        } 
    }
    for(int i = 0;i < N;i++) {
        v.push_back(1);
    }

    vector<int> result;

    while(next_permutation(v.begin(),v.end())) {
        int count = 1;
        vector<int> A;
        for(int i = 0;i < (int)v.size();i++) {
            if(v[i] == 1) {
                A.push_back(count);
            }
            else{
                count++;
            }
        }
        long long sum = 0;
        for(int i = 0; i < Q; i++) {
            if(A[b[i]-1] - A[a[i]-1] == c[i]) {
                sum += d[i];
            }
        }
        result.push_back(sum);
    }

    cout << *max_element(result.begin(),result.end()) << endl;

    return 0;

    
}