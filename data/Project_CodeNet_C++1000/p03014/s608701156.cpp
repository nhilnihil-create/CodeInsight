#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

template <typename TYPE>
void print_vec(const vector<TYPE>& v){
	for(int i=0; i<v.size(); i++){
		cout << v[i] << " ";
	}
	cout << endl;
}

template <typename TYPE>
void print_vec2(const vector<vector<TYPE>>& v){
  cout << endl; cout << "       ";
  for(int i=0; i<v[0].size(); i++) cout << i << "   "; 
  cout << endl;
	for(int i=0; i<v.size(); i++){
		cout << "i=" << i << ":   ";
		for(int j=0; j<v[i].size(); j++){
			if(v[i][j] == 0) cout << "\x1B[0m" << v[i][j] << "   ";
      else cout << "\x1B[31m" << v[i][j] << "   ";//https://stackoverrun.com/ja/q/12618775
		}
		cout << "\x1B[0m" << endl;
	}
}

using P = pair<int, int>;
int main(){
	int H, W;
	cin >> H >> W;
	vector<string> S(H);
	for(int i=0; i<H; i++) cin >> S[i];

	int dy[] = {-1, 1};
	vector<vector<int>> tate(H, vector<int>(W, 0));
	for(int h=0; h<H; h++){
		for(int w=0; w<W; w++){
			if(tate[h][w] != 0) continue;
			if(S[h][w] == '#') continue;
			queue<P> qu;
			qu.push(P(h, w));
			int cnt = 1;
			tate[h][w] = cnt;
			while(!qu.empty()){
				int y = qu.front().first;
				int x = qu.front().second;
				qu.pop();
				for(int i=0; i<2; i++){
					int ny = y + dy[i];
					int nx = x;
					if(ny<0 || H<= ny) continue;
					if(S[ny][nx] == '#') continue;
					if(tate[ny][nx] != 0) continue;
					tate[ny][nx] = tate[y][x] + 1;
					cnt = max(cnt, tate[ny][nx]);
					qu.push(P(ny, nx));
					// cout << "  (h, w)=(" << h<<", "<<w <<"),  (y, x)=(" << y << ", " << x << ")   (ny, nx)=(" << ny << ", " << nx << ")" << endl;
				}
			}
			qu.push(P(h, w));
			tate[h][w] = cnt;
			while(!qu.empty()){
				int y = qu.front().first;
				int x = qu.front().second;
				qu.pop();
				for(int i=0; i<2; i++){
					int ny = y + dy[i];
					int nx = x;
					if(ny<0 || H<= ny) continue;
					if(S[ny][nx] == '#') continue;
					if(tate[ny][nx] == cnt) continue;
					tate[ny][nx] = cnt;
					qu.push(P(ny, nx));
					
				}
			}
		}
	}
	// cout << " tate: "; print_vec2(tate);
	int dx[] = {-1, 1};
	vector<vector<int>> yoko(H, vector<int>(W, 0));
	for(int h=0; h<H; h++){
		for(int w=0; w<W; w++){
			if(yoko[h][w] != 0) continue;
			if(S[h][w] == '#') continue;
			queue<P> qu;
			qu.push(P(h, w));
			int cnt = 1;
			yoko[h][w] = cnt;
			while(!qu.empty()){
				int y = qu.front().first;
				int x = qu.front().second;
				qu.pop();
				for(int i=0; i<2; i++){
					int ny = y;
					int nx = x + dx[i];
					if(nx<0 || W<= nx) continue;
					if(S[ny][nx] == '#') continue;
					if(yoko[ny][nx] != 0) continue;
					yoko[ny][nx] = yoko[y][x] + 1;
					cnt = max(cnt, yoko[ny][nx]);
					qu.push(P(ny, nx));
				}
			}
			qu.push(P(h, w));
			yoko[h][w] = cnt;
			while(!qu.empty()){
				int y = qu.front().first;
				int x = qu.front().second;
				qu.pop();
				for(int i=0; i<2; i++){
					int ny = y;
					int nx = x + dx[i];
					if(nx<0 || W<= nx) continue;
					if(S[ny][nx] == '#') continue;
					if(yoko[ny][nx] == cnt) continue;
					yoko[ny][nx] = cnt;
					qu.push(P(ny, nx));
					
				}
			}
		}
	}
	// cout << " yoko: "; print_vec2(yoko);
	int ans = 0;
	vector<vector<int>> sum(H, vector<int>(W, 0));
	for(int h=0; h<H; h++){
		for(int w=0; w<W; w++){
			sum[h][w] = tate[h][w] + yoko[h][w] - 1;
			ans = max(ans, sum[h][w]);
		}
	}
	cout << ans << endl;
}

