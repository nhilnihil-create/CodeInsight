#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

int N;
int M;
pair<int,int> PD[10000+10];

int main() {
  while (cin >> N >> M && N) {
    int d,p;
    for (int i=0;i<N;i++) {
      cin >> d >> p;
      PD[i] = make_pair(p,d);
      //PD[i].firstは道iの危険度
      //PD[i].secondは道iの長さ
    }
    sort(PD,PD+N);
    reverse(PD,PD+N);
    //    for (int i=0;i<N;i++) {
    //  cout << "kiken: " << PD[i].first << endl;
    //  cout << "nagasa: " << PD[i].second << endl;
    //}
    int S=0; // 全部足してから引く
    for (int i=0; i<N; i++) {
      S += PD[i].first * PD[i].second;
    }
    for (int i=0; i<N; i++) {
      if (M <= 0) {
	break;
      } else {
	int guarded = min(M,PD[i].second);
	S -= PD[i].first * guarded;
	M -= guarded;
      }
    }
    cout << S << endl;
  }
}