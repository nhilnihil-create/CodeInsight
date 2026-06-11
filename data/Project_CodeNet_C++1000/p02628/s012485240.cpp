#include <bits/stdc++.h>

using namespace std;
long long sum = 0;
int main(){
      int N , K;  cin >> N >> K;
      vector<int>v(N);
      for (int i=0; i<N; ++i)  cin >> v[i];
       sort(v.begin(), v.end());
      for(int i=0; i<K; ++i) sum += v[i];

      cout << sum << endl;
      return 0;
}