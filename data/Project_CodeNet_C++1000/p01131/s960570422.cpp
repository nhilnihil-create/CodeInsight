#include <iostream>
#include <string>
#include <map>
#include <typeinfo>
#include <cxxabi.h>
#define type_name(class)  demangle((typeid(class)).name())
char* demangle(const char *demangle) {
    int status;
    return abi::__cxa_demangle(demangle, 0, 0, &status);
}

using namespace std;

class ButtonForwarder{
private:
	string m_chars;
	int m_nchars;
	unsigned int m_pos;
public:
	ButtonForwarder(){}
	ButtonForwarder(const string& str){
		m_chars = str;
		m_nchars = str.size();
		m_pos = -1;
	} 
	~ButtonForwarder(){}
	void push_button(){
		if(m_pos == m_nchars-1){
			m_pos = 0;
		}else{
			m_pos++;
		}
	}
	const string getCharacter(){
		// cout<<"In getCharacter() string is "<<m_chars<<endl;
		// cout<<"m_pos = "<<m_pos<<endl;
		return m_chars.substr(m_pos,1);
	}
	void reset(){m_pos=-1;}
};

class CellularKeyboard{
private:
	map<string, ButtonForwarder> m_buttons;
	string m_curButton;
	string result_temp;
public:
	CellularKeyboard(){m_curButton="";result_temp="";}
	void setStrings(string button, string chars){
		ButtonForwarder bf(chars);
		m_buttons[button] = bf;
	}
	string push(string button){
		// cout<<"push("<< button <<")"<<endl;
		//確定ボタン(キー0が押された場合)
		if(button == "0"){
			//何もボタンが押されていないときに確定ボタンを押すことはできるが、
			//その場合には何も文字は出力されない。
			if(m_curButton.length()==0){return string("");}
			
			// cout<<m_curButton<<endl;
			result_temp = m_buttons[m_curButton].getCharacter();
			m_buttons[m_curButton].reset();
			m_curButton = "";
			return result_temp;
		}
		m_curButton = button;
		m_buttons[button].push_button();
		// cout<<&(m_buttons[button])<<endl;
		// cout<<"Button"<<button<<" is "<<m_buttons[button].getCharacter()<<endl;
		return string("");
	}
};

int main() {
	// your code goes here
	CellularKeyboard kbd;
	kbd.setStrings(string("1"), string(".,!? "));
	kbd.setStrings(string("2"), string("abc"));
	kbd.setStrings(string("3"), string("def"));
	kbd.setStrings(string("4"), string("ghi"));
	kbd.setStrings(string("5"), string("jkl"));
	kbd.setStrings(string("6"), string("mno"));
	kbd.setStrings(string("7"), string("pqrs"));
	kbd.setStrings(string("8"), string("tuv"));
	kbd.setStrings(string("9"), string("wxyz"));
	
	int num;
	string input, decoded;
	cin>>num;
	for(int n=0;n<num;n++){
		cin>>input;
		decoded="";
		for(int i=0;i<input.length();i++){
			decoded += kbd.push(input.substr(i,1));
		}
		cout<<decoded<<endl;
	}
	
	// string input, decoded;
	// input ="000555555550000330000444000080000200004440000";
	// for(int i=0;i<input.length();i++){
	// 	// cout<<"char : "<<input.substr(i,1)<<" => "<<kbd.push(input.substr(i,1))<<endl;
	// 	decoded += kbd.push(input.substr(i,1));
	// }
	// cout<<decoded<<endl;
	return 0;
}