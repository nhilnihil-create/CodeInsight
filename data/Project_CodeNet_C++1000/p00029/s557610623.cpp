#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;



int main()
{
	vector<string> word;
	string sent;
	int ss = 0;
	getline(cin, sent);
	//input word
	for(int i = 0; i < sent.size(); i++)
	{
		if(sent[i] == ' ' )
		{
			
			word.push_back(sent.substr(ss,i - ss));
			int inc = 1,tmp = i;
			while(1)
			{
				if(!(sent[tmp+1] == ' ') )	break;
				++inc; ++tmp;
			}
			ss = i + inc;
		}
		if(i == sent.size() - 1)
		{
			word.push_back(sent.substr(ss, (i+1) - ss));
		}
	}
	
	int leng = 0, p = 0;
	//length
	for(int i = 0;i < word.size(); i++)
	{
		if(word[i].size() > leng)
		{
			leng = word[i].size();
			p = i;
		}
	}
	//cout << word[p] << endl;
	//frequency
	/*
	int bucket[1024];
	for(int i = 0; i < 1024; i++) bucket[i] = 0;
	
	vector<string> list;

	for(int i = 0; i < word.size(); i++)
	{
		if( list.empty() || !( find(list.begin(), list.end(), word[i]) == list.end() ) )
		{
			list.push_back(word[i]);
		}
		for(int i = 0; i < list.size(); i++)
		{
			cout << list[i] << endl;
		}
	}
	*/
	
	map<string, int> freq;
	for(int i = 0;i < word.size(); i++)
	{
		bool judge = false;

		if(freq.find(word[i]) == freq.end())
		{
			freq.insert(make_pair<string,int>(word[i], 1));
		}
		else
		{
			freq[ word[i] ]++;
		}
	}
	map<string, int>::iterator it, high;
	leng = 0;
	for(it = freq.begin(); it != freq.end(); it++)
	{
		if( leng < (*it).second)
		{
			leng = (*it).second;
			high = it;
		}	
		//cout << (*it).first << (*it).second << endl;
	}
	cout << (*high).first << ' ' << word[p] << endl;
}