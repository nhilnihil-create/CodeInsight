#include <bits/stdc++.h>
using namespace std;
int main(){
int H,W,a,b; cin>>H>>W>>a>>b;
int counter=0;
int counter1=0;
for(int i=0;i<b;i++){
for(int j=0;j<W;j++){
if(counter<a){
cout<<0;}
else{
cout<<1;}
counter++;}
cout<<endl;
counter=0;
}
counter=0;
for(int i=0;i<H-b;i++){
for(int j=0;j<W;j++){
if(counter<a){
cout<<1;}
else{
cout<<0;}
counter++;}
cout<<endl;
counter=0;
}}

