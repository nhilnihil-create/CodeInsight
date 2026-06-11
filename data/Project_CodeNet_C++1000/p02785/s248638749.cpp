#include <bits/stdc++.h>

using i16 = std::int16_t;
using i32 = std::int32_t;
using i64 = std::int64_t;
using usize = std::size_t;
template<typename T>
using Vector = std::vector<T>;
using String = std::string;
template<typename T>
using UniquePointer = std::unique_ptr<T>;
using namespace std;

#define rep(i, max) for(usize i = 0; i < max; ++i)
#define loop while(true)

UniquePointer<String> readLine() {
    UniquePointer<String> line(new String());
    getline(cin, *line);
    return line;
}

template<typename T1, typename T2>
pair<T1, T2> readPair(){
    T1 res1;
    cin >> res1;
    T2 res2;
    cin >> res2;
    readLine();
    return make_pair(res1, res2);
}

template<typename T>
UniquePointer<Vector<T>> readVector(usize num) {
    UniquePointer<Vector<T>> list(new Vector<T>(num));
    rep(i, num) {
        cin >> (*list)[i];
    }
    readLine();
    return list;
}

void readValues()
{
    readLine();
}

template<typename H, typename... T>
void readValues(H& head, T&&... tails){
    H a;
    cin >> a;
    head = a;
    readValues(forward<T>(tails)...);
}

template<typename T>
void writeLine(T arg) {
    cout << arg << endl;
}

template<typename T>
void write(T arg) {
    cout << arg << std::flush;
}

void program();

int main()
{
    ios::sync_with_stdio(false);
    program();
}

void program() {
    int n, k;
    readValues(n, k);
    if(k > n){
        readLine();
        writeLine(0);
        return;
    }
    auto h = readVector<i32>(n);
    sort(h->begin(), h->end());
    writeLine(accumulate(h->begin(), h->end() - k, 0LL));
}