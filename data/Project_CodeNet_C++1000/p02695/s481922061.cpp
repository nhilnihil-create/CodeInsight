// In god we trust
 
#include <bits/stdc++.h>
#include <chrono>
#include <algorithm>
#include <signal.h>
#include <thread>
 
#define pb push_back
#define fi first
#define se second
#define Vi vector<int>
#define Vb vector<bool>
#define Pi pair<int, int>
#define MP make_pair
#define MT make_tuple
#define Q queue
#define Qi Q<int>
#define INF 1000000000 
#define LINF 1000000000000000000
#define int long long
using namespace std;
using namespace std::chrono;

unordered_map<int, int> factor(int n){
  int cnt = 0;
  unordered_map<int, int> m;
  int nn = n;
  while (!(nn & 1))
    cnt++, nn /= 2;
  if(cnt)
    m[2] = cnt;
  for (int i = 3; i <= sqrt(n); i++){
    cnt = 0;
    while(nn % i == 0)
      nn /= i, cnt++;
    if (cnt)
      m[i] = cnt;
  }
  if (nn > 2)
    m[nn] = 1;
  
  return m;
}

signed main(){
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);

  int n, m, q;
  cin >> n >> m >> q;
  int a[q], b[q], c[q], d[q];
  for (int i = 0; i < q; i++){
    cin >> a[i] >> b[i] >> c[i] >> d[i];
    a[i]--, b[i]--;
  }


  Vi v;
  int max_ = 0;
  v.resize(20);
  if (n == 2){
    for (int i1 = 1; i1 <= m; i1++)
      for (int i2 = i1; i2 <= m; i2++){
	v[0] = i1, v[1] = i2;
	int s = 0;
	for (int i = 0; i < q; i++)
	  s += d[i] * (v[b[i]] - v[a[i]] == c[i]);
	max_ = max(max_, s);
      }
	
  }

  if (n == 3){
    for (int i1 = 1; i1 <= m; i1++)
      for (int i2 = i1; i2 <= m; i2++)
	for(int i3 = i2; i3 <= m; i3++){
	  v[0] = i1, v[1] = i2, v[2] = i3;
	  int s = 0;
	  for (int i = 0; i < q; i++)
	    s += d[i] * (v[b[i]] - v[a[i]] == c[i]);
	  max_ = max(max_, s);
      }
  }

  if (n == 4){
    for (int i1 = 1; i1 <= m; i1++)
      for (int i2 = i1; i2 <= m; i2++)
	for(int i3 = i2; i3 <= m; i3++)
	  for (int i4 = i3; i4 <= m; i4++){
	    v[0] = i1, v[1] = i2, v[2] = i3, v[3] = i4;
	    int s = 0;
	    for (int i = 0; i < q; i++)
	      s += d[i] * (v[b[i]] - v[a[i]] == c[i]);
	    max_ = max(max_, s);
      }

  }

  if(n == 5){
    for (int i1 = 1; i1 <= m; i1++)
      for (int i2 = i1; i2 <= m; i2++)
	for(int i3 = i2; i3 <= m; i3++)
	  for(int i4 = i3; i4 <= m; i4++)
	    for (int i5 = i4; i5 <= m; i5++){
	      v[0] = i1, v[1] = i2, v[2] = i3, v[3] = i4, v[4] = i5;
	      int s = 0;
	      for (int i = 0; i < q; i++)
		s += d[i] * (v[b[i]] - v[a[i]] == c[i]);
	      max_ = max(max_, s);
      }
  }

  if (n == 6){
    for (int i1 = 1; i1 <= m; i1++)
      for (int i2 = i1; i2 <= m; i2++)
	for(int i3 = i2; i3 <= m; i3++)
	  for(int i4 = i3; i4 <= m; i4++)
	    for (int i5 = i4; i5 <= m; i5++)
	      for (int i6 = i5; i6 <= m; i6++){
		v[0] = i1, v[1] = i2, v[2] = i3, v[3] = i4, v[4] = i5, v[5] = i6;
		int s = 0;
		for (int i = 0; i < q; i++)
		  s += d[i] * (v[b[i]] - v[a[i]] == c[i]);
		max_ = max(max_, s);
      }

  }
  if(n == 7){
    for (int i1 = 1; i1 <= m; i1++)
      for (int i2 = i1; i2 <= m; i2++)
	for(int i3 = i2; i3 <= m; i3++)
	  for(int i4 = i3; i4 <= m; i4++)
	    for (int i5 = i4; i5 <= m; i5++)
	      for (int i6 = i5; i6 <= m; i6++)
		for (int i7 = i6; i7 <= m; i7++){
		  v[0] = i1, v[1] = i2, v[2] = i3, v[3] = i4, v[4] = i5, v[5] = i6, v[6] = i7;
		  int s = 0;
		  for (int i = 0; i < q; i++)
		    s += d[i] * (v[b[i]] - v[a[i]] == c[i]);
		  max_ = max(max_, s);
      }
  }

  if(n == 8){
    for (int i1 = 1; i1 <= m; i1++)
      for (int i2 = i1; i2 <= m; i2++)
	for(int i3 = i2; i3 <= m; i3++)
	  for(int i4 = i3; i4 <= m; i4++)
	    for (int i5 = i4; i5 <= m; i5++)
	      for (int i6 = i5; i6 <= m; i6++)
		for (int i7 = i6; i7 <= m; i7++)
		  for (int i8 = i7; i8 <= m; i8++){
		    v[0] = i1, v[1] = i2, v[2] = i3, v[3] = i4, v[4] = i5, v[5] = i6, v[6] = i7, v[7] = i8;
		    int s = 0;
		    for (int i = 0; i < q; i++)
		      s += d[i] * (v[b[i]] - v[a[i]] == c[i]);
		    max_ = max(max_, s);
      }
  }

  if(n == 9){
    for (int i1 = 1; i1 <= m; i1++)
      for (int i2 = i1; i2 <= m; i2++)
	for(int i3 = i2; i3 <= m; i3++)
	  for(int i4 = i3; i4 <= m; i4++)
	    for (int i5 = i4; i5 <= m; i5++)
	      for (int i6 = i5; i6 <= m; i6++)
		for (int i7 = i6; i7 <= m; i7++)
		  for (int i8 = i7; i8 <= m; i8++)
		    for (int i9 = i8; i9 <= m; i9++){
		      v[0] = i1, v[1] = i2, v[2] = i3, v[3] = i4, v[4] = i5, v[5] = i6, v[6] = i7, v[7] = i8, v[8] = i9;
		      int s = 0;
		      for (int i = 0; i < q; i++)
			s += d[i] * (v[b[i]] - v[a[i]] == c[i]);
		      max_ = max(max_, s);
      }
  }
  
  if (n == 10){
    for (int i1 = 1; i1 <= m; i1++)
      for (int i2 = i1; i2 <= m; i2++)
	for(int i3 = i2; i3 <= m; i3++)
	  for(int i4 = i3; i4 <= m; i4++)
	    for (int i5 = i4; i5 <= m; i5++)
	      for (int i6 = i5; i6 <= m; i6++)
		for (int i7 = i6; i7 <= m; i7++)
		  for (int i8 = i7; i8 <= m; i8++)
		    for (int i9 = i8; i9 <= m; i9++)
		      for (int i10 = i9; i10 <= m; i10++){
			v[0] = i1, v[1] = i2, v[2] = i3, v[3] = i4, v[4] = i5, v[5] = i6, v[6] = i7, v[7] = i8, v[8] = i9, v[9] = i10;
			int s = 0;
			for (int i = 0; i < q; i++)
			  s += d[i] * (v[b[i]] - v[a[i]] == c[i]);
			max_ = max(max_, s);
      }
  }

  cout << max_ << endl;


}
