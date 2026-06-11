  #include <bits/stdc++.h>
  using namespace std;
  vector<vector<int>> gr;
  int n, q;
  struct DSU{ 
      vector<int> par, siz;
      int n;
      DSU(int n_) {
          int n = n_ + 1;
          par.resize(n);
          siz.resize(n);
          fill(siz.begin(), siz.end(), 1);
          iota(par.begin(), par.end(), 0);
      }

      int get(int v) {
          if(par[v] == v) {
              return v;
          }
          return par[v] = get(par[v]);
      }
      void uni(int l, int r) {
          l = get(l);
          r = get(r);
          if(l != r) {
              if(siz[l] > siz[r]) {
                  swap(l, r);
			}
			par[l] = r;
			siz[r] += siz[l];
		}
	}
};
main() {
	cin >> n >>	q;

	DSU dsu(n);

	gr = vector<vector<int>> (n + 1, vector<int> ());
	while(q--) {
		int id;
		cin >> id;
		int l, r;
   	cin >> l >> r;
		if(id) {
     	cout << (dsu.get(l) == dsu.get(r)) << endl;
		} else {
  		dsu.uni(l, r);
		}
	}
}