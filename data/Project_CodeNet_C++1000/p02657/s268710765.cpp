#include <bits/stdc++.h>
using namespace std;

//abbriviations
typedef long long int ll;
typedef vector<ll> vll;
// typedef vector v;
typedef pair<ll,ll> pll;
typedef priority_queue<ll> pqll;

#define repi(i,a,b) for(ll i=a;i<b;i++)
#define rep(x,v) for(auto &x : v)
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()

//theory


// set<data type> s;->or multiset;
// s.insert(x);->adds element x 
// t=s.count(x);->0 or 1 in case of ordered while returns number of occourances in case of unordered set
// t=s.size();->returns number of elements 
// t=s.find(x);->returns a pointer to element x 
// t=s.begin(),s.end()->can be used to iteratre over the elements in sorted order
// t=s.upper_bound(x) or (v.begin(),v.end(),x),s.lower_bound(x)->returns a pointer to ub or lb ,returns s.end()if desired bound is not found;
// s.erase(x)->x can be an iterator/element(all occourances are deleted i.e. count becomes 0)/or a range i.e start pointer end pointer;
// s.erase(s.find(x))->to delete a single occourance in case of a multiset;
//can be iterated using rep(x,s) meathod;

// map<datatype1,datatype2> m;
// m[x]=y; x becomes key and y becomes value if x already existed its over written
// t=m.count(x) returns 0 or 1 depending up existance of x;
// rep(x,v)meathod works ;
// t=m.size();

// priority_queue<int> q; 
// q.push(x);pushes 
// t=q.top() ;returns the max element
// q.pop();
// priority_queue<int,vector<int>,greater<int>> q;->allows us to create a reverse priority queue;


// deque<int> d; 
// d.push_back(5); // [5] 
// d.push_back(2); // [5,2] 
// d.push_front(3); // [3,5,2] 
// d.pop_back(); // [3,5] 
// d.pop_front(); // [5]

// stack<int> s;
// s.push(2); // [2]
// s.push(5); // [2,5]
// cout << s.top() << "\n"; // 5 s.pop(); // [2]
// cout << s.top() << "\n"; // 2

// queue<int> q;
// q.push(2); // [2]
// q.push(5); // [2,5]
// cout << q.front() << "\n"; // 2 q.pop(); // [5]
// cout << q.back() << "\n"; // 5

//bitset<n> a,b; //a&b,a|b,a^b,~a

//vector<datatype> a(x,y),b(z);->x&z are predefining size , y helps to set a default value
// string s;
// getline(cin, s);
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
// printf("%.9f\n", x);

// __builtin_clz(x): the number of zeros at the beginning of the bit represen- tation
// __builtin_ctz(x): the number of zeros at the end of the bit representation
// __builtin_popcount(x): the number of ones in the bit representation
// __builtin_parity(x): the parity (even or odd) of the number of ones in the bit representation

//max(a,b)->returns the larger among a and b
//min(a,b)->returns the smaller among a and b
//swap(a,b)->swap the values of a and b

//sort(s.begin(), s.end());->will sort elements in range s.begin till s.end
//Pairs are sorted primarily according to their first elements and secondarily according to their second elements.
//In a similar way, tuples are sorted primarily by the first element, secondarily by the second element, etc.
// struct point { 
 //   int x, y;
    // bool operator<(const point &p) { 
    //     if (x == p.x) return y < p.y; 
    //     else return x < p.x;
// } };
// bool comp(string a, string b) {
// if (a.size() == b.size()) return a < b; 
// else return a.size() < b.size();
// }
//sort(v.begin(), v.end(), comp);

// reverse(v.begin(),v.end());
// random_shuffle(v.begin(),v.end());

// lower_bound gives an iterator to the first element in a sorted range whose value is at least x ,
//  and upper_bound gives an iterator to the first element whose value is larger than x:
// vector<int> v = {2,3,3,5,7,8,8,8};
// auto a = lower_bound(v.begin(),v.end(),5); 
// auto b = upper_bound(v.begin(),v.end(),5); 
// cout << *a << " " << *b << "\n"; // 5 7




//code

//stl for next permutation
// do 
//     {
//         //process s
//     } 
// while (next_permutation(s.begin(),s.end()));

//recursive code for processing all permutations
// void search() {
// if (permutation.size() == n) {
// // process permutation } else {
// for (int i = 1; i <= n; i++) 
// { 
//     if (chosen[i]) continue; 
//     chosen[i] = true;
//     permutation.push_back(i); 
//     search();
//     chosen[i] = false;
//     permutation.pop_back();
// }
// } }

//binary search implimaentation
// int a = 0, b = n-1; while (a <= b) {
// int k = (a+b)/2;
// if (array[k] == x) {
//        // x found at index k
//     }
// if (array[k] < x) a = k+1;
// else b = k-1; }

//binary search implimaentation
//int k = 0;
// for (int b = n/2; b >= 1; b /= 2) {
// while (k+b < n && array[k+b] <= x) k += b; }
// if (array[k] == x) {
// // x found at index k
// }

//binary search for validity
// int x = -1;
// for (int b = z; b >= 1; b /= 2) {
// while (!valid(x+b)) x += b; }
// int k = x+1;

//  creates a vector that contains the unique elements of the original vector in a sorted order:
// sort(v.begin(),v.end());
// v.erase(unique(v.begin(),v.end()),v.end());

long long __gcd(ll a, ll b) 
{ 
    if (b == 0) 
        return a; 
    return __gcd(b, a % b);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a,b;
    cin>>a>>b;
    cout<<a*b;

    return 0;
}  