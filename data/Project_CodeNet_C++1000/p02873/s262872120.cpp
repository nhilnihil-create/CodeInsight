#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
int main() {
    string S; cin>>S;
    long long counter=0;
    long long counter1=0;
    long long counter2=0;
    long long answer=0;
    if(S.at(0)=='<'){
    counter++;}
    else
    counter1++;
    for(long long i=1; i<S.size(); i++){
    if(counter>0&&counter2==0){
    if(S.at(i)=='<'){
    counter++;
    continue;}
    else{
    answer+=counter*(counter+1)/2;
    counter1++;
    counter2=counter;
    counter=0;
    continue;}}
    else {
    if(S.at(i)=='>'){
    counter1++;
    continue;}
    else{
    answer+=counter1*(counter1-1)/2+max((counter1-counter2),0LL);
    counter++;
    counter2=0;
    counter1=0;
    continue;}}}
    answer+=counter*(counter+1)/2;
    answer+=counter1*(counter1-1)/2+max((counter1-counter2),0LL);
    cout<<answer<<endl;}
    
      
    
    
