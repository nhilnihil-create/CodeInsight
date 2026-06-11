# 1 "a.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "a.cpp"
# 1 "/home/tysm/dev/cpplib/bin/../include/cpplib/stdinc.hpp" 1
       
# 11 "/home/tysm/dev/cpplib/bin/../include/cpplib/stdinc.hpp"
# 1 "/home/tysm/dev/cpplib/bin/../stdlib/bits/stdc++.h" 1
 #include<bits/stdc++.h>
# 12 "/home/tysm/dev/cpplib/bin/../include/cpplib/stdinc.hpp" 2
# 1 "/home/tysm/dev/cpplib/bin/../stdlib/ext/pb_ds/assoc_container.hpp" 1
 #include<ext/pb_ds/assoc_container.hpp>
# 13 "/home/tysm/dev/cpplib/bin/../include/cpplib/stdinc.hpp" 2
# 1 "/home/tysm/dev/cpplib/bin/../stdlib/ext/pb_ds/tree_policy.hpp" 1
 #include<ext/pb_ds/tree_policy.hpp>
# 14 "/home/tysm/dev/cpplib/bin/../include/cpplib/stdinc.hpp" 2
# 23 "/home/tysm/dev/cpplib/bin/../include/cpplib/stdinc.hpp"
using namespace std;
using namespace __gnu_pbds;

using ii = pair<int64_t, int64_t>;
using tt = tuple<int64_t, int64_t, int64_t>;

using vi = vector<int64_t>;
using vd = vector<double>;
using vb = vector<bool>;
using vii = vector<ii>;
using vtt = vector<tt>;

using vvi = vector<vi>;
using vvd = vector<vd>;
using vvb = vector<vb>;
using vvii = vector<vii>;
using vvtt = vector<vtt>;
# 60 "/home/tysm/dev/cpplib/bin/../include/cpplib/stdinc.hpp"
template<typename T>
ostream &operator<<(ostream &lhs, const vector<T> &rhs)
{
    if(is_floating_point<T>::value)
        lhs << fixed << setprecision(10);
    for(size_t i = 0; i < rhs.size(); ++i) {
        if(i)
            lhs << ' ';
        lhs << rhs[i];
    }
    return lhs;
}

template<typename T, size_t N>
ostream &operator<<(ostream &lhs, const array<T, N> &rhs)
{
    if(is_floating_point<T>::value)
        lhs << fixed << setprecision(10);
    for(size_t i = 0; i < rhs.size(); ++i) {
        if(i)
            lhs << ' ';
        lhs << rhs[i];
    }
    return lhs;
}
# 2 "a.cpp" 2


int32_t main(){
    (ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL));
    int64_t d, t, s;
    cin >> d >> t >> s;
    cout << (s*t >= d? "Yes" : "No") << "\n";
    return 0;
}
