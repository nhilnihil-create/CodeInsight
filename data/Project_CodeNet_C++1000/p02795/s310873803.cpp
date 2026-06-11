#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define vi vector<int>

#define ll long long int

int ctoi(char c) {return c-'0';}
int ord(char c) {return c-'a';}
int len(string s) {return s.length();}
int itoc(int i) {return i+'a';}

int main() {
int H,W,N;
cin>>H>>W>>N;
H = max(H,W);
cout<<(N%H==0 ? N/H : (N/H)+1)<<endl;
return 0;
}
