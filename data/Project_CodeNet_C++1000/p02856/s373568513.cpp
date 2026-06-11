// #define _GLIBCXX_DEBUG
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;using pll = pair<ll, ll>;using pdd = pair<double, double>;using pss = pair<string, string>;using pbb = pair<bool, bool>;
using ti3 = tuple<int, int, int>;using tl3 = tuple<ll, ll, ll>;using td3 = tuple<double, double, double>;using ts3 = tuple<string, string, string>;using tb3 = tuple<bool, bool, bool>;
using ti4 = tuple<int, int, int, int>;using tl4 = tuple<ll, ll, ll, ll>;using td4 = tuple<double, double, double, double>;using ts4 = tuple<string, string, string, string>;using tb4 = tuple<bool, bool, bool, bool>;
using vi = vector<int>;using vl = vector<ll>;using vd = vector<double>;using vs = vector<string>;using vb = vector<bool>;
using vvi = vector<vi>;using vvl = vector<vl>;using vvd = vector<vd>;using vvs = vector<vs>;using vvb = vector<vb>;
using v3i = vector<vvi>;using v3l = vector<vvl>;using v3d = vector<vvd>;using v3s = vector<vvs>;using v3b = vector<vvb>;
using vpii = vector<pii>;using vpll = vector<pll>;using vpdd = vector<pdd>;using vpss = vector<pss>;using vpbb = vector<pbb>;
using vti3 = vector<ti3>;using vtl3 = vector<tl3>;using vtd3 = vector<td3>;using vts3 = vector<ts3>;using vtb3 = vector<tb3>;
using mii = map<int, int>;using mll = map<ll, ll>;using mci = map<char, int>;using msi = map<string, int>;
using si = set<int>;using sl = set<ll>;using sd = set<double>;using ss = set<string>;using sb = set<bool>;
using spii = set<pii>;using spll = set<pll>;using spdd = set<pdd>;using spss = set<pss>;using spbb = set<pbb>;
using sti3 = set<ti3>;using stl3 = set<tl3>;using std3 = set<td3>;using sts3 = set<ts3>;using stb3 = set<tb3>;
#define rep0(TIMES) for (int CNT = 0; CNT < (int)(TIMES); CNT++)
#define rep(CNT, GOAL) for (int CNT = 0; CNT < (int)(GOAL); CNT++)
#define rep2(CNT, START, GOAL) for (ll CNT = (ll)(START); CNT < (ll)(GOAL); CNT++)
#define rep3(CNT, START, GOAL) for (ll CNT = (ll)(START); CNT > (ll)(GOAL); CNT--)
#define all(CONT) begin(CONT), end(CONT)
#define fr1(CONT) next(begin(CONT)), end(CONT)
#define itrep(ITR, CONT) for (auto ITR = begin(CONT); ITR != end(CONT); ITR++)
#define itrep1(ITR, CONT) for (auto ITR = next(begin(CONT)); ITR != end(CONT); ITR++)
#define maxel(CONT) *max_element(all(CONT))
#define minel(CONT) *min_element(all(CONT))
template <typename T> bool chmax(T &a, const T &b) { if (a < b) {	a = b; return true;	}	return false; }
template <typename T> bool chmin(T &a, const T &b) { if (a > b) {	a = b; return true;	}	return false; }
template <typename T> T sum(const vector<T> &VEC) { return accumulate(all(VEC), 0.0); }
template <typename T> vector<T> acm(const vector<T> &VEC) { vector<T> RES(VEC.size() + 1); rep(CNT, VEC.size()) RES[CNT + 1] = RES[CNT] + VEC[CNT];	return RES; }
template <typename T> void fil(vector<T> &VEC, const int NUM, const T &VAL) { VEC.assign(NUM, VAL); }
template <typename T> void fil(vector<T> &VEC, const int NUM) { VEC.assign(NUM, 0.0); }
template <typename T> void fil(vector<vector<T>> &VV, const int RNUM, const int CNUM, const T &VAL) { fil(VV, RNUM, vector<T>()); rep(CNT, RNUM) fil(VV[CNT], CNUM, VAL); }
template <typename T> void fil(vector<vector<T>> &VV, const int RNUM, const int CNUM) { fil(VV, RNUM, vector<T>()); rep(CNT, RNUM) fil(VV[CNT], CNUM); }
template <typename T> void fil(vector<vector<T>> &VV, const int RNUM) { fil(VV, RNUM, vector<T>()); }
void prec(const int &DIG) { cerr << fixed << setprecision(DIG); cout << fixed << setprecision(DIG); }
template <typename T> void COUT(const T &ELEM) { cout << ELEM; }
template <typename T> void pout(const T &ELEM) { COUT(ELEM); cout << " "; }
template <typename T, typename ...Ts> void pout(const T &FIRST, const Ts &...REST) { pout(FIRST); pout(REST...); }
template <typename T> void print(T ELEM) { COUT(ELEM); cout << "\n"; }
template <typename T, typename ...Ts> void print(const T &FIRST, const Ts &...REST) { print(FIRST); print(REST...); }
void CERR() { cerr << "\n"; }
template <typename T> void CERR(const T &ELEM) { cerr << ELEM; }
template <typename T, typename ...Ts> void CERR(const T &FIRST, const Ts &...REST) { CERR(FIRST); cerr << ", "; CERR(REST...); }
template <typename T1, typename T2> void CERR(const pair<T1, T2> &PAIR) { cerr << "("; CERR(PAIR.first); cerr << ", "; CERR(PAIR.second); cerr << ")"; }
template <typename T1, typename T2, typename T3> void CERR(const tuple<T1, T2, T3> &TUP3) { cerr << "("; CERR(get<0>(TUP3)); cerr << ", "; CERR(get<1>(TUP3)); cerr << ", "; CERR(get<2>(TUP3)); cerr << ")"; }
template <typename T1, typename T2, typename T3, typename T4> void CERR(const tuple<T1, T2, T3, T4> &TUP4) { cerr << "("; CERR(get<0>(TUP4)); cerr << ", "; CERR(get<1>(TUP4)); cerr << ", "; CERR(get<2>(TUP4)); cerr << ", "; CERR(get<3>(TUP4)); cerr << ")"; }
template <typename T> void CERR(const vector<T> &VEC) { cerr << "{ "; itrep(ITR, VEC) { CERR(*ITR); cerr << ", "; } cerr << "}"; }
template <typename T> void CERR1(const vector<T> &VEC) { cerr << "{ "; itrep1(ITR, VEC) { CERR(*ITR); cerr << ", "; } cerr << "}"; }
template <typename T> void CERR(const set<T> &SET) { cerr << "{ "; itrep(ITR, SET) { CERR(*ITR); cerr << ", "; } cerr << "}"; }
template <typename T1, typename T2> void CERR(const map<T1, T2> &MAP) { cerr << "{ "; itrep(ITR, MAP) { CERR(*ITR); cerr << ", "; } cerr << "}"; }
#define db(OBJ) cerr << #OBJ << ": "; CERR(OBJ); cerr << ", "
#define dbl(OBJ) cerr << #OBJ << ": "; CERR(OBJ); cerr << "\n"
#define db1(OBJ) cerr << #OBJ << ": "; CERR1(OBJ); cerr << "\n"
#define dbs(...) cerr << "(" << #__VA_ARGS__ << "): ("; CERR(__VA_ARGS__); cerr << ")\n"
#define dbvv(VV) cerr << #VV << ": {\n"; rep(CNT, VV.size()) { cerr << #VV << "[" << CNT << "]: "; CERR(VV[CNT]); cerr << ",\n"; } cerr << "}\n"
#define db01(VV) cerr << #VV << ": {\n"; rep(CNT, VV.size()) { cerr << #VV << "[" << CNT << "]: "; CERR1(VV[CNT]); cerr << ",\n"; } cerr << "}\n"
#define db10(VV) cerr << #VV << ": {\n"; rep2(CNT, 1, VV.size()) { cerr << #VV << "[" << CNT << "]: "; CERR(VV[CNT]); cerr << ",\n"; } cerr << "}\n"
#define db11(VV) cerr << #VV << ": {\n"; rep2(CNT, 1, VV.size()) { cerr << #VV << "[" << CNT << "]: "; CERR1(VV[CNT]); cerr << ",\n"; } cerr << "}\n"
#define YN(f) cout << (f ? "YES" : "NO") << "\n"
#define Yn(f) cout << (f ? "Yes" : "No") << "\n"
#define yn(f) cout << (f ? "yes" : "no") << "\n"
#define pcase(NUM) cout << "Case #" << NUM << ":" << " "
#define pcasel(NUM) cout << "Case #" << NUM << ":" << "\n"
// db

// 操作1回により，
// (ア) 桁数が1減り，桁和が不変 (繰り上がらず)
// (イ) 桁数が減らず，桁和が9減る (繰り上がる)
// のいずれかなので，「桁数 * 9 - 桁和」は不変，
// 操作の回数(ア+イ) = 桁数の減少回数(ア) + (桁和の減少 / 9)(イ) である。
// （桁和が減少しなかったとすれば，操作が可能なのは(当初の桁数-1)回であるが，実際には，(当初の桁和 - 最後の桁和) / 9 回多く操作できる。）
// 操作ができなくなったとき，数字の個数 = 1, 桁和はその数字の値であり，これは(当初の桁和 mod 9)(>0)に等しい。
// (当初の桁数 - 1) + (当初の桁和 - ((当初の桁和-1)mod 9) + 1)) / 9 が答え。
int main() {
	int M; cin >> M;
	ll dsum = 0, dig = 0;
	rep0(M) {
		ll d, c; cin >> d >> c;
		dsum += d * c;
		dig += c;		
	}
	// dbs(dsum, dig);
	ll ans = 0;
	ans += dig - 1;
	ans += (dsum - (((dsum - 1) % 9) + 1)) / 9;
	print(ans);	
}