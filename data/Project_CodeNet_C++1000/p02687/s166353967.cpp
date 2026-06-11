#include<iostream>
#include<string>

using namespace std;

/*
	Name:Atcoder ABC166 A 
	Copyright:NONE 
	Author: CHAIN
	Date: 15-08-20 18:15
	Description: AtCoder Inc. holds a contest every Saturday.There are two types
	of contests called ABC and ARC, and just one of them is held at a time.The 
	company holds these two types of contests alternately: an ARC follows an 
	ABC and vice versa.Given a string S, resenting the type of the contest held
	last week, print the string representing the type of the contest held this
	week.
*/

int main(){
	string s;
	cin>>s;
	cout<< (s =="ABC"?"ARC":"ABC")<<'\n';
	return 0;
} 