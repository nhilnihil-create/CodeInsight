#include <iostream>
#include <bits/stdc++.h>
#include <stdio.h>

typedef long long ll;
using namespace std;

//class Node{
//public:
//    ll value;
//    Node* parent;
//    Node* leftChild;
//    Node* rightChild;
//    int left;
//    int right;
//    Node(int value,){
//
//    }
//};


bool isPrime(int n){
    if(n < 2){
        return 0;
    }
    if(n%2 == 0){
        return n==2;
    }
    for(int i=3;i*i<=n;i++){
        if(n%i == 0) return 0;
    }
    return 1;
}


int main() {
   string s,t;
   cin>>s>>t;
   int d = 0;
   for(int i=0;i<s.size();i++){
       if(s[i] != t[i])d++;
   }
   cout<<d<<endl;
    return 0;
}
