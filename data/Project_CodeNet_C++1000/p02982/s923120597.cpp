#include <bits/stdc++.h>
using namespace std;

bool is_integer( double x ){
  return floor(x)==x;
}

void recursive_comb(int *indexes, int s, int rest, std::function<void(int *)> f) {
  if (rest == 0) {
    f(indexes);
  } else {
    if (s < 0) return;
    recursive_comb(indexes, s - 1, rest, f);
    indexes[rest - 1] = s;
    recursive_comb(indexes, s - 1, rest - 1, f);
  }
}

// nCkの組み合わせに対して処理を実行する
void foreach_comb(int n, int k, std::function<void(int *)> f) {
  int indexes[k];
  recursive_comb(indexes, n - 1, k, f);
}

double Distance(int *p_1,int *p_2,int D){
    
    double sum = 0;
    
    for(int i=0;i<D;i++){
        int r,l;
        l = *(p_1 + i);
        r = *(p_2 + i);
        sum += pow((r-l),2);
    }
    
    return sqrt(sum);
}

int main(void){
    
    int N,D,ans = 0;
    cin >> N >> D;

    int data[N][D];
    vector<int> nums {};
    int *p = &data[0][0];
    for(int i=0;i<N;i++) nums.push_back(i);
    
    for(int i=0;i<N;i++){
        for(int j=0;j<D;j++){
            cin >> data[i][j];
        }
    }
    
    foreach_comb(N, 2, [&](int *indexes) {
        if(is_integer(Distance((p+indexes[0] * D), (p+indexes[1] * D),D))) ans++;
    
    });
    
    cout << ans << endl;
}