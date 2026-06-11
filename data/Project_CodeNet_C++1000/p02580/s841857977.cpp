#include <iostream>
#include <math.h>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>

#define DOLL long double
#define LOLI long long int
using namespace std;

const long C_10PW9 = 1000000000;
const int ULCODE = 32;

int main()
{
	int H, W, M;
	cin >> H >> W >> M;
	vector<int> Height(H), Width(W);
	vector<pair<int, int>> BOM;
	for (int i = 0; i < M; i++) {
		int hi, wi;
		cin >> hi >> wi;
		Height[hi - 1]++;
		Width[wi - 1]++;
		BOM.push_back(make_pair<int, int>(hi - 1, wi - 1));
	}
	auto Hbeg = Height.begin();
	auto hinx = distance(Hbeg, max_element(Hbeg, Height.end()));
	auto Wbeg = Width.begin();
	auto winx = distance(Wbeg, max_element(Wbeg, Width.end()));
	int HM = Height[hinx], WM = Width[winx];
	LOLI HC = 0, WC = 0;
	for (int i = 0; i < H; i++) { if (Height[i] == HM) { HC++; } }
	for (int i = 0; i < W; i++) { if (Width[i] == WM) { WC++; } }
	LOLI HWC = HC * WC;
	for (int i = 0; i < M; i++) {
		int h = BOM[i].first, w = BOM[i].second;
		if (Height[h] == HM && Width[w] == WM) { HWC--; }
	}
	int vec = 0;
	if (HWC <= 0) { vec = -1; }
	cout << HM + WM + vec << endl;

	return 0;
}